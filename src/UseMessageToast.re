open Belt;

type message = {
  expires: float,
  text: string,
};

let defaultTimeToLive = 3000.;
let not = (fn, x) => !fn(x);
let expired = (now, message) => now > message.expires;
let nextExpire = messages => {
  messages->List.get(0);
};

let hook = (~now=Js.Date.now, ~ttl=defaultTimeToLive, initialMessages) => {
  let (messages, setMessages) = React.useState(() => initialMessages);
  React.useEffect1(
    () =>
      switch (nextExpire(messages)) {
      | None => None
      | Some(nextTimeoutMilis) =>
        let timeoutId =
          Js.Global.setTimeout(
            () =>
              setMessages(messages =>
                messages->List.keep(not(expired(now())))
              ),
            int_of_float(nextTimeoutMilis.expires -. now()),
          );
        Some(() => Js.Global.clearTimeout(timeoutId));
      },
    [|messages|],
  );

  let addMessage = text =>
    setMessages(messages =>
      List.concat(messages, [{expires: Js.Date.now() +. ttl, text}])
    );
  (messages, addMessage);
};
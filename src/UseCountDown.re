let (useState, useEffect2) = React.(useState, useEffect2);
let (setTimeout, clearTimeout) = Js.Global.(setTimeout, clearTimeout);

let decrement = x => x - 1;

[@genType]
let default = (interval, run, onFinished) => {
  let (timeToLaunch, setTimeToLaunch) = useState(() => interval);

  useEffect2(
    () =>
      run
        ? if (timeToLaunch > 0) {
            let timerId = setTimeout(() => setTimeToLaunch(decrement), 1000);
            Some(() => clearTimeout(timerId));
          } else {
            onFinished();
            None;
          }
        : None,
    (timeToLaunch, run),
  );
  timeToLaunch;
};

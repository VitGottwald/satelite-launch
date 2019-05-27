let n = x => x->string_of_int->React.string;

[@react.component]
let make = (~interval, ~run, ~onFinished) => {
  let timeToLaunch = UseCountDown.default(interval, run, onFinished);

  <div className="countdown"> timeToLaunch->n </div>;
};

[@genType]
let default = make;

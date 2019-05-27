[@react.component]
let make = (~launch) => {
  let launchClass = launch ? "launched" : "";
  <div className={j|rocket $(launchClass)|j}>
    <Payload />
    <Rocket />
    <Fire />
  </div>;
};

/* export as typescript component */
[@genType]
let default = make;

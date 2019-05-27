[@react.component]
let make = (~className) => {
  <div className={j|rocket $(className)|j}>
    <Payload />
    <Rocket />
    <Fire />
  </div>;
};

/* export as typescript component */
[@genType]
let default = make;

[@genType]
[@react.component]
let make = (~className) => {
  <div className={j|rocket $(className)|j}>
    <Payload />
    <Rocket />
    <Fire />
  </div>;
};

open Belt;
let s = React.string;

[@react.component]
[@genType]
let make = (~header) => {
  let (messages, addMessage) = UseMessageToast.hook();
  <div>
    <h2> header->s </h2>
    <button onClick={_ => addMessage(Js.Date.toString(Js.Date.make()))}>
      "Add Message"->s
    </button>
    <ul>
      {messages->Array.map(message => <li> message.text->s </li>)->React.array}
    </ul>
  </div>;
};

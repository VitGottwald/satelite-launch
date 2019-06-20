import * as React from 'react';
import {hook as useMessageToast} from './UseMessageToast.gen';

const MessageToast = ({header}: {header: string}) => {
  let [messages, addMessage] = useMessageToast();
  return (
    <>
      <div>
        <h2>{header}</h2>
        <button onClick={_ => addMessage(Date().toString())}>
          Add Message
        </button>
        <ul>
          {messages.map(message => (
            <li> {message.text} </li>
          ))}
        </ul>
      </div>
    </>
  );
};

export default MessageToast;

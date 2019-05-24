import * as React from "react";
import { make as WorldMap } from "./WorldMap.gen";

const MessageToast = ({ header}: {header: string})=> (
  <>
    <div>
      <h1>{header}</h1>
    </div>
    <WorldMap header="App Header" />
  </>
);

export default MessageToast;

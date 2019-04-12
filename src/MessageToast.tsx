import * as React from "react";
import * as App from "./App.gen";

const messageToast = ({ header }: { header: string }) => (
  <div>
    <h1>{header}</h1>
    <App.make sth="Pepa" />
  </div>
);

export default messageToast;

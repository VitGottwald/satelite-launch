import * as React from "react";
import TSMessageToast from "./TSMessageToast";
import { make as MessageToast } from "./MessageToast.gen";
import { make as WorldMap } from "./WorldMap.gen";
import Rocket from "./Rocket";

const TSApp = ({ title }: { title: string }) => (
  <>
    <div>
      <h2>{title}</h2>
    </div>
    <MessageToast header="Toaster" />
    <WorldMap header="Cities" />
    <Rocket />
  </>
);

export default TSApp;

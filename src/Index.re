include GlobalStyles;

module MessageToast = {
  [@genType.import ("./MessageToast", "default")] [@react.component]
  external make: (~header: string) => React.element = "";
};

ReactDOMRe.renderToElementWithId(
  <MessageToast header="Message Toast Header" />,
  "root",
);

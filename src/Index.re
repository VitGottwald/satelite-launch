include GlobalStyles;

module MessageToast = {
  [@genType.import ("./MessageToast", "default")] [@react.component]
  external make: (~text: string) => React.element = "";
};

ReactDOMRe.renderToElementWithId(<MessageToast text="Karel" />, "root");

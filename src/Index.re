module TSApp = {
  [@genType.import ("./TSApp", "default")] [@react.component]
  external make: (~title: string) => React.element = "";
};

ReactDOMRe.renderToElementWithId(<TSApp title="App" />, "root");

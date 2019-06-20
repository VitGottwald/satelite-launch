module TSApp = {
  [@genType.import ("./TSApp", "default")] [@react.component]
  external make: _ => React.element = "";
};

ReactDOMRe.renderToElementWithId(<TSApp />, "root");
include GlobalStyles;

module Mxxx = {
  [@genType.import "./Blah.tsx"] [@react.component]
  external blah: (~text: string) => React.element = "";
};

ReactDOMRe.renderToElementWithId(<Mxxx.blah text="Karel" />, "root");
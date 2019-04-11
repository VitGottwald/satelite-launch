type position = (float, float);
module Map = {
  [@bs.module "react-leaflet"] [@react.component]
  external make:
    (
      ~center: position,
      ~zoom: int,
      ~className: string,
      ~children: React.element
    ) =>
    React.element =
    "Map";
};

module TileLayer = {
  [@bs.module "react-leaflet"] [@react.component]
  external make: (~url: string) => React.element = "TileLayer";
};

module Marker = {
  [@bs.module "react-leaflet"] [@react.component]
  external make:
    (~position: position, ~children: React.element=?) => React.element =
    "Marker";
};

module Popup = {
  [@bs.module "react-leaflet"] [@react.component]
  external make: (~children: React.element) => React.element = "Popup";
};
module Map = {
  [@bs.module "react-leaflet"] [@react.component]
  external make:
    (
      ~center: (float, float),
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
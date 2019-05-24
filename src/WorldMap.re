open Belt;
let s = React.string;

[@react.component]
[@genType]
let make = (~header) => {
  <div>
    <h2> header->s </h2>
    <ul>
      {Data.cities
       ->List.map(city => <li key={city.id}> city.name->s </li>)
       ->List.toArray
       ->React.array}
    </ul>
    <Leaflet.Map center=(10., 10.) zoom=1 className=Styles.mapClass>
      <Leaflet.tileLayer
        url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
      />
      {Data.cities
       ->List.map(city =>
           <Leaflet.Marker
             key={city.id}
             position=(city.coordinates.lat, city.coordinates.lng)>
             <Leaflet.popup>
               <p> city.name->s </p>
               <img className=Styles.imageClass src={city.image.url} />
             </Leaflet.popup>
           </Leaflet.Marker>
         )
       ->List.toArray
       ->React.array}
    </Leaflet.Map>
  </div>;
};

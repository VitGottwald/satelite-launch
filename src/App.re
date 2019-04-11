open Belt;
let s = React.string;
[@react.component]
let make = () =>
  <div>
    <h1> "Cities"->s </h1>
    <ul>
      {Data.cities
       ->List.map(city => <li key={city.id}> city.name->s </li>)
       ->List.toArray
       ->React.array}
    </ul>
    <Leaflet.Map center=(10., 10.) zoom=1 className=Styles.mapClass>
      <Leaflet.TileLayer
        url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
      />
      {Data.cities
       ->List.map(city =>
           <Leaflet.Marker
             key={city.id}
             position=(city.coordinates.lat, city.coordinates.lng)>
             <Leaflet.Popup>
               <p> city.name->s </p>
               <img className=Styles.imageClass src={city.image.url} />
             </Leaflet.Popup>
           </Leaflet.Marker>
         )
       ->List.toArray
       ->React.array}
    </Leaflet.Map>
  </div>;
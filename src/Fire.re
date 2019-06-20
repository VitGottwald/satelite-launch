/* import react component from typescript */
[@genType.import ("./TSFire", "default")] [@react.component]
external make: _ => React.element = "";

/* export as typescript component */
[@genType]
let default = make;
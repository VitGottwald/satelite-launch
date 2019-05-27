/* import react component from typescript */
[@genType.import ("./TSRocket", "default")] [@react.component]
external make: _ => React.element = "";

/* export as typescript component */
[@genType]
let ts = make;

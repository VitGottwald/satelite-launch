[@bs.send] external map: (array('a), 'a => 'b) => array('b) = "map";
[@bs.send] external filter: (array('a), 'a => bool) => array('a) = "filter";

[|1, 2, 3|]->map(a => a + 1)->filter(a => a mod 2 == 0)->Js.log;
/* 2, 4 */

[@bs.module "path"] [@bs.variadic]
external join: array(string) => string = "join";
let v = join([|"a", "b", "c"|]);
Js.log(v);

[@bs.val]
external padLeft:
  (string, [@bs.unwrap] [ | `Str(string) | `Int(int)]) => string =
  "padLeft";

/* padLeft("Hello World", `Int(4)); */
/* padLeft("Hello World", `Str("4")); */

let add = (. x, y, z) => x + y + z;
let six = add(. 1, 2, 3);

[@bs.val] external setTimeout: (unit => unit, int) => float = "setTimeout";

setTimeout(() => Js.log("----- KAREL"), 5000);

[@bs.module "path"] external dirname: string => string = "dirname";
Js.log(dirname("../"));

let add: (int, int) => int = [%raw
  {|
  function(a, b) {
    console.log("hello from raw JavaScript!");
    return a + b
  }
|}
];

let f: (int, int) => int = [%raw (a, b) => {|
  return a + b
|}];

Js.log(add(1, 2));
Js.log(f(2, 3));

switch ([%external __filename]) {
| Some(fileName) => Js.log(fileName)
| None => Js.log("non-node environment")
};

/* Object types */
type person = {. name: string}; /* this does not compile to simple JS object */

/* type jsPerson = Js.t({. name: string}); */
type jsPerson = {. "name": string};

let karel = {"name": "Karel"};
let pepa = {"name": "Pepa"};

type openPerson('a) = {.. name: string} as 'a;

Js.log(karel##name);

%raw
{|
  function draw(x, y, border) {
    console.log(x, y, border)
  }
|};

[@bs.val]
external draw: (~x: int, ~y: int, ~border: string=?, unit) => unit = "draw";

draw(~x=10, ~y=10, ());

type document; /* abstract type for a document object */
[@bs.send]
external getElementById: (document, string) => Dom.element = "getElementById";
[@bs.val] external doc: document = "document";

let el = getElementById(doc, "root");
Js.log(el);

let make = () => {
  Js.log("experiment");
};

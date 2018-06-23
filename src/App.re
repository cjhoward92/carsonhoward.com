/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.statelessComponent("App");

type div;
[@bs.send] external scrollIntoView : (div) => unit = "";
let myDiv : div = [%bs.raw {| document.getElementById("secondary") |}];

let onScrollClick = (_event) => {
  scrollIntoView(myDiv);
}

let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: self => {
    let clickMessage = "Click to scroll";
    <div
      className="app"
    >
      <App2 greeting="Hey, the build worked!" />
      <button onClick=onScrollClick>
        (ReasonReact.string(clickMessage))
      </button>
    </div>;
  },
};

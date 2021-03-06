/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: (_self) => {
    <div
      className="app"
    >
      <Nav />
    </div>;
  },
};

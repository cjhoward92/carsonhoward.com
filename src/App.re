/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.statelessComponent("App");

let appStyle = ReactDOMRe.Style.make(
  ~color="red",
  ~background="green",
  ~margin="0 auto",
  ~padding="0",
  ()
);

let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: _self => {
    <div
      style=(appStyle)
    >
      <App2 greeting="Hello" />
    </div>;
  },
};

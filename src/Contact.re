let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="contact">
      <a href="mailto:cjhoward92@gmail.com">
        (ReasonReact.string("Email me as cjhoward92@gmail.com!"))
      </a>
    </div>;
  },
};

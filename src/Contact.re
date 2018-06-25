let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="contact">
      <a href="mailto:carson@carsonhoward.com">
        (ReasonReact.string("Email me!"))
      </a>
    </div>;
  },
};

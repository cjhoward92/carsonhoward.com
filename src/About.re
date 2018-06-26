let component = ReasonReact.statelessComponent("About");

let aboutMe = "
I am not a designer, that's for sure. This site is built with ReasonReact and deployed on AWS.
It also builds and deploys automatically when I push to GitHub, so there's that. Feel free to
view the source code 
";

let aboutMe2 = "
if you are so inclined. Otherwise, don't. Your call.
";

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="about">
      <div>
        <img src="/at_desk.png" alt="Me at a desk!" />
        <p>
          (ReasonReact.string(aboutMe))
          <a href="https://github.com/cjhoward92/carsonhoward.com">(ReasonReact.string("here"))</a>
          (ReasonReact.string(aboutMe2))
        </p>
        <p className="github"><a href="https://github.com/cjhoward92">(ReasonReact.string("Visit my GitHub Profile!"))</a></p>
      </div>
    </div>
  }
};

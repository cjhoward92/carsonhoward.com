let component = ReasonReact.statelessComponent("About");

let aboutMe = "
NOTE: IF YOU FOUND THIS THE WEBSITE IS IN SUPER WIP MODE! STILL WORKING ON IT DAILY!
This site is built with ReasonReact. It was an experiement.
I am Carson. I am a developer. I am not a designer. I guess we will see what this looks like when done...
";

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="about">
      <div>
        <img src="/Shaka_me.jpg" alt="Me in Hawaii" />
        <p className="github"><a href="https://github.com/cjhoward92">(ReasonReact.string("Visit my GitHub Profile!"))</a></p>
        <p>
          (ReasonReact.string(aboutMe))
        </p>
      </div>
    </div>
  }
};

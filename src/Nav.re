let component = ReasonReact.statelessComponent("Nav");

type div;
[@bs.send] external scrollIntoView : (div) => unit = "";
let wordsDiv : div = [%bs.raw {| document.getElementById("words") |}];
let contactDiv : div = [%bs.raw {| document.getElementById("contact") |}];

let makeScrollOnClick = (divToScroll) => (_event) => {
  scrollIntoView(divToScroll);
}

let make = (_children) => {
  ...component,
  render: (_self) => {
    let scrollToWords = makeScrollOnClick(wordsDiv);
    let scrollToContact = makeScrollOnClick(contactDiv);
    <ul className="navbar">
      <li className="brand-container">
        <p className="brand">(ReasonReact.string("Carson Howard"))</p>
      </li>
      <li>
        <button
          className="nav-button"
          onClick=scrollToWords
        >
          (ReasonReact.string("About Me"))
        </button>
      </li>
      <li>
        <button
          className="nav-button"
          onClick=scrollToContact
        >
          (ReasonReact.string("Contact"))
        </button>
      </li>
      <li>
        <a
          className="resume-link"
          href="mailto:cjhoward92@gmail.com?subject=Resume"
        >
          (ReasonReact.string("Resume"))
        </a>
      </li>
    </ul>
  },
};

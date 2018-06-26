/* State declaration */
type state = {
  skills: bool,
  experience: bool,
  education: bool,
};

/* Action declaration */
type action = Collapse(string) | Expand(string);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Resume");

let collapseExpandSection = (sectionName, collapse, state) => {
  switch (sectionName) {
  | "skills" => ReasonReact.Update({...state, skills: collapse})
  | "experience" => ReasonReact.Update({...state, experience: collapse})
  | "education" => ReasonReact.Update({...state, education: collapse})
  | _ => ReasonReact.NoUpdate
  }
};

let onCollapseExpand = (sectionCollapsed, section, sendFn) => {
  let actionToSend = sectionCollapsed ? Expand(section) : Collapse(section);
  sendFn(actionToSend);
};

let makeResumeSectionClasses = (collapsed) => {
  let initialClasses = "resume-section";
  collapsed ? initialClasses ++ " collapsed" : initialClasses;
};

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {skills: false, experience: false, education: false},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Collapse(section) => collapseExpandSection(section, true, state)
    | Expand(section) => collapseExpandSection(section, false, state)
    },

  render: self => {
    <div className="resume">
      <div className=(makeResumeSectionClasses(self.state.experience))>
        <button onClick=(_event => onCollapseExpand(self.state.experience, "experience", self.send))>
          (ReasonReact.string("Work Experience"))
        </button>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Axosoft LLC / Senior Developer / June 2017 - Present"))
          </li>
          <li>
            (ReasonReact.string("- Enabled GitKraken Enterprise support for major LDAP providers (AD, OpenLDAP, etc.)"))
          </li>
          <li>
            (ReasonReact.string("- Contributed to the NodeGit and libgit2 C/C++ libraries to add new git features to GitKraken"))
          </li>
          <li>
            (ReasonReact.string("- Created Git LFS/GitKraken interoperability layer with Node.js and bash commands"))
          </li>
          <li>
            (ReasonReact.string("- Migrated large set of live subscription data to microservices with zero downtime"))
          </li>
          <li>
            (ReasonReact.string("- Saw a 100%+ increase in daily active users and managed scalability concerns"))
          </li>
        </ul>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Trilogy Ed - University of Arizona Bootcamp / TA / July 2017 - January 2018"))
          </li>
          <li>
            (ReasonReact.string("- Mentored students to become full-fledged web developers"))
          </li>
          <li>
            (ReasonReact.string("- Collaborated with instructors and TAs to deliver impactful course content"))
          </li>
          <li>
            (ReasonReact.string("- Achieving curriculum milestones through disciplined time and content management"))
          </li>
        </ul>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Koch Foods, Inc / Lead Developer / August 2016 - June 2017"))
          </li>
          <li>
            (ReasonReact.string("- Standardized code format and style to aid in application maintainability and new developer onboarding"))
          </li>
          <li>
            (ReasonReact.string("- Implemented a Continuous Integration Pipeline to create a tight feedback loop during development"))
          </li>
          <li>
            (ReasonReact.string("- Mentored other developers in use of OOP design principles in managing application complexity"))
          </li>
          <li>
            (ReasonReact.string("- Rewrote a pivotal warehouse management tool based on a decade-old legacy application originally written in a foreign language using WPF"))
          </li>
          <li>
            (ReasonReact.string("- Designed and deployed additional applications used in daily operation of 20+ production plants"))
          </li>
        </ul>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Aspen Systems / Development Manager / September 2015 - August 2016"))
          </li>
          <li>
            (ReasonReact.string("- Interpreted customer requirements into functional specifications for developer use"))
          </li>
          <li>
            (ReasonReact.string("- Produced statement of work and negotiated prices for client projects"))
          </li>
          <li>
            (ReasonReact.string("- Promoted collaboration and life-long learning by leading bi-monthly development meetings"))
          </li>
          <li>
            (ReasonReact.string("- Managed early team-based development of a delivery routing mobile application"))
          </li>
        </ul>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Aspen Systems / Developer / February 2014 - September 2015"))
          </li>
          <li>
            (ReasonReact.string("- Maintained and enhanced a monolithic ERP system that underwent frequent change and exponential code base growth"))
          </li>
          <li>
            (ReasonReact.string("- Designed and deployed an ASP.NET MVC web front-end to an existing CRM module"))
          </li>
          <li>
            (ReasonReact.string("- Implemented database wide T-SQL schema changes that impacted an entire suite of enterprise applications"))
          </li>
        </ul>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Loffa Interactive / Junior Developer / June 2013 - February 2014"))
          </li>
          <li>
            (ReasonReact.string("- Maintained a legacy ASP.NET Web Application used for Financial Institution Document Management"))
          </li>
        </ul>
      </div>
      <div className=(makeResumeSectionClasses(self.state.skills))>
        <button onClick=(_event => onCollapseExpand(self.state.skills, "skills", self.send))>
          (ReasonReact.string("Skills"))
        </button>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Tech Stack"))
          </li>
          <li>
            (ReasonReact.string("C# - F# - Node.js - JavaScript - TypeScript - T-SQL/MySQL - C/C++ - MongoDB - ASP.NET - React/Redux - Docker - LDAP - WPF"))
          </li>
          <li className="resume-header">
            (ReasonReact.string("Design and Arshitecture"))
          </li>
          <li>
            (ReasonReact.string("Microservices - SOLID - GoF Design Principles - Dependency Management - Domain Driven Design"))
          </li>
          <li className="resume-header">
            (ReasonReact.string("Soft Skills"))
          </li>
          <li>
            (ReasonReact.string("Excellent Communication - Management - Leadership - Client Interaction - Requirements Gathering - Teaching"))
          </li>
        </ul>
      </div>
      <div className=(makeResumeSectionClasses(self.state.education))>
        <button onClick=(_event => onCollapseExpand(self.state.education, "education", self.send))>
          (ReasonReact.string("Education"))
        </button>
        <ul className="resume-list">
          <li className="resume-header">
            (ReasonReact.string("Arizona State University"))
          </li>
          <li>
            (ReasonReact.string("B.S. in Computer Information Systems - May 2014"))
          </li>
          <li>
            (ReasonReact.string("Summa Cum Laude"))
          </li>
        </ul>
      </div>
    </div>;
  },
};

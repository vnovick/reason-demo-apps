[@bs.val] external require: string => string = "";
let logo = require("../imgs/logo.svg");

[@react.component]
let make = (~openModal, ~isModalOpened) => {
  <header className="flex mb-4 sticky top-0">
    <nav className="w-full bg-gray-100  p-5">
      <div
        className="justify-between flex max-w-6xl md:mx-10 lg:mx-10 xl:mx-10">
        <img src=logo className="w-10 h-10  mr-4" />
        <h1 className="text-center md:text-xl md:text-l sm:text-s">
          {"ReasonML Blog CMS Built with GraphQL using Hasura and Netlify functions"
           |> ReasonReact.string}
        </h1>
        <button
          disabled=isModalOpened
          onClick={e => {
            ReactEvent.Synthetic.stopPropagation(e);
            openModal();
          }}
          className={
            "shadow bg-purple-500 focus:shadow-outline focus:outline-none text-white font-bold py-2 px-4 rounded s sm:text-sm md:text-lg text-xs"
            ++ (
              if (isModalOpened) {" animated pulse opacity-50 "} else {
                " hover:bg-purple-400"
              }
            )
          }>
          {"Add blog post" |> ReasonReact.string}
        </button>
      </div>
    </nav>
  </header>;
};
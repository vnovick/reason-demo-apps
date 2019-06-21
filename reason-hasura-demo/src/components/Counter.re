type action =
  | Inc
  | Dec;
type state = {count: int};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Inc => {count: state.count + 1}
        | Dec =>
          switch (state.count) {
          | 0 => {count: 0}
          | _ => {count: state.count - 1}
          }
        },
      {count: 0},
    );
  <div className="container">
    <h3 className="w-auto ml-10 text-2xl">
      {state.count |> string_of_int |> ReasonReact.string}
    </h3>
    <button
      className="button m-2 border p-2 shadow-md"
      onClick={_ => dispatch(Inc)}>
      {"+" |> ReasonReact.string}
    </button>
    <button
      className="button m-2 border p-2 shadow-md"
      onClick={_ => dispatch(Dec)}>
      {"-" |> ReasonReact.string}
    </button>
  </div>;
};
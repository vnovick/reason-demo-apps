type modalAction =
  | Open
  | Close;

type state = {isModalOpened: bool};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | Open => {isModalOpened: true}
        | Close => {isModalOpened: false}
        },
      {isModalOpened: false},
    );
  <div onClick={_ => dispatch(Close)}>
    <Header
      openModal={_ => dispatch(Open)}
      isModalOpened={state.isModalOpened}
    />
    {state.isModalOpened
       ? <Modal closeModal={_ => dispatch(Close)} /> : ReasonReact.null}
    <PostsList />
    <Counter />
  </div>;
};
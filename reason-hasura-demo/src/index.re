%raw
"import './App.css'";
%raw
"import 'animate.css'";

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client={ApolloClient.makeApolloClient()}>
    <App />
  </ReasonApollo.Provider>,
  "root",
);
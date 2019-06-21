%raw
"import './index.css'";
%raw
"import 'animate.css'";

[@bs.module "./serviceWorker"]
external register_service_worker: unit => unit = "register";
[@bs.module "./serviceWorker"]
external unregister_service_worker: unit => unit = "unregister";

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client={ApolloClient.makeApolloClient()}>
    <App />
  </ReasonApollo.Provider>,
  "root",
);

unregister_service_worker();
// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE

import * as ApolloLinks from "reason-apollo/src/ApolloLinks.bs.js";
import * as ApolloLink from "apollo-link";
import * as ReasonApollo from "reason-apollo/src/ReasonApollo.bs.js";
import * as ApolloUtilities from "apollo-utilities";
import * as ApolloInMemoryCache from "reason-apollo/src/ApolloInMemoryCache.bs.js";

function makeApolloClient(param) {
  var inMemoryCache = ApolloInMemoryCache.createInMemoryCache(undefined, undefined, /* () */0);
  var webSocketLink = ApolloLinks.webSocketLink("ws://localhost:8080/v1/graphql", true, undefined, /* () */0);
  var httpLink = ApolloLinks.createHttpLink("http://localhost:8080/v1/graphql", undefined, undefined, undefined, undefined, undefined, /* () */0);
  var webSocketHttpLink = ApolloLink.split((function (operation) {
          var operationDefition = ApolloUtilities.getMainDefinition(operation.query);
          if (operationDefition.kind === "OperationDefinition") {
            return operationDefition.operation === "subscription";
          } else {
            return false;
          }
        }), webSocketLink, httpLink);
  return ReasonApollo.createApolloClient(webSocketHttpLink, inMemoryCache, undefined, undefined, undefined, undefined, /* () */0);
}

export {
  makeApolloClient ,
  
}
/* ApolloLinks Not a pure module */

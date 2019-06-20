let makeApolloClient = _ => {
  // Create an InMemoryCache
  let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

  let webSocketLink =
    ApolloLinks.webSocketLink(
      ~uri="ws://localhost:8080/v1/graphql",
      ~reconnect=true,
      (),
    );

  let httpLink =
    ApolloLinks.createHttpLink(~uri="http://localhost:8080/v1/graphql", ());
  /* based on test, execute left or right */
  let webSocketHttpLink =
    ApolloLinks.split(
      operation => {
        let operationDefition =
          ApolloUtilities.getMainDefinition(operation##query);
        operationDefition##kind == "OperationDefinition"
        &&
        operationDefition##operation == "subscription";
      },
      webSocketLink,
      httpLink,
    );

  // return apollo client instance
  ReasonApollo.createApolloClient(
    ~link=webSocketHttpLink,
    ~cache=inMemoryCache,
    (),
  );
};
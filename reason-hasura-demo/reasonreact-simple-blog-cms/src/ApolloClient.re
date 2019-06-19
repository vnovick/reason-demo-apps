let makeApolloClient = _ => {
  // Create an InMemoryCache
  let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

  // Create an HTTP Link
  let httpLink =
    ApolloLinks.createHttpLink(~uri="http://localhost:8080/v1/graphql", ());

  // return apollo client instance
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
};
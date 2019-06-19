module PostMutation = [%graphql
  {|
     mutation addPost($title: String!, $content: String!, $sanitize: Boolean, $coverImg: String){
      insert_posts(objects: {user_id: "first-user-with-dummy-id", title: $title, content: $content, sanitize: $sanitize, cover_img: $coverImg }) {
        affected_rows
      }
    }
  |}
];

module AddPostMutation = ReasonApollo.CreateMutation(PostMutation);

[@react.component]
let make = (~closeModal) => {
  let (title, setTitle) = React.useState(() => "");
  let (content, setContent) = React.useState(() => "");
  let (sanitize, setSanitize) = React.useState(() => false);
  let (coverImg, setCoverImage) =
    React.useState(() =>
      "https://images.unsplash.com/photo-1555397430-57791c75748a?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=500&q=80"
    );
  <AddPostMutation>
    ...{(mutation, _) => {
      let addNewPostMutation =
        PostMutation.make(~title, ~content, ~sanitize, ~coverImg, ());
      let addNewPost = _ => {
        closeModal();
        mutation(
          ~variables=addNewPostMutation##variables,
          // ~refetchQueries=[|"getPosts"|],
          (),
        )
        |> ignore;
      };
      <form
        className="w-full"
        onSubmit={event => {
          event->ReactEvent.Form.preventDefault;
          addNewPost();
        }}>
        <div className="md:flex md:items-center mb-6">
          <div className="md:w-1/12">
            <label
              className="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
              htmlFor="inline-full-name">
              {"Title" |> ReasonReact.string}
            </label>
          </div>
          <div className="md:w-11/12">
            <input
              onChange={e => e->ReactEvent.Form.target##value |> setTitle}
              className="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
              id="inline-full-name"
              type_="text"
              placeholder="Enter your title"
              value=title
            />
          </div>
        </div>
        <div className="md:flex md:items-center mb-6">
          <div className="md:w-1/12">
            <label
              className="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
              htmlFor="inline-image">
              {"Cover image url" |> ReasonReact.string}
            </label>
          </div>
          <div className="md:w-11/12">
            <input
              onChange={e => e->ReactEvent.Form.target##value |> setCoverImage}
              className="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
              id="inline-image"
              type_="text"
              value=coverImg
            />
          </div>
        </div>
        <div className="md:flex md:items-center mb-6">
          <div className="md:w-1/12">
            <label
              className="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
              htmlFor="inline-username">
              {"Content" |> ReasonReact.string}
            </label>
          </div>
          <div className="md:w-11/12">
            <textarea
              className="h-20 bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
              id="inline-username"
              type_="text"
              onChange={e => e->ReactEvent.Form.target##value |> setContent}
              value=content
              placeholder="Write your post content"
            />
          </div>
        </div>
        <div className="md:flex md:items-center mb-6">
          <div className="md:w-1/12" />
          <label className="md:w-11/12 block text-gray-500 font-bold">
            <input
              className="mr-2 leading-tight"
              type_="checkbox"
              checked=sanitize
              onChange={e => e->ReactEvent.Form.target##checked |> setSanitize}
            />
            <span className="text-sm">
              {"Check bad words" |> ReasonReact.string}
            </span>
          </label>
        </div>
        <div className="md:flex md:items-center">
          <div className="md:w-1/12" />
          <div className="md:w-11/12">
            <button
              onClick={_ => addNewPost()}
              className="shadow bg-purple-500 hover:bg-purple-400 focus:shadow-outline focus:outline-none text-white font-bold py-2 px-4 rounded"
              type_="button">
              {"Submit" |> ReasonReact.string}
            </button>
          </div>
        </div>
      </form>;
    }}
  </AddPostMutation>;
};
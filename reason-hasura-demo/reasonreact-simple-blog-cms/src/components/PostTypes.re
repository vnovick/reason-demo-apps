type user = {
  name: string,
  avatar_url: string,
};
type post = {
  title: string,
  cover_img: option(string),
  content: string,
  created_at: Js.Json.t,
  user,
};
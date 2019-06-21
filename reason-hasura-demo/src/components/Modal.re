[@react.component]
let make = (~closeModal) => {
  <div className="absolute border w-11/12 z-10 bg-gray-100 shadow-md p-5 modal-center animated zoomInUp"     onClick={event => ReactEvent.Synthetic.stopPropagation(event)}>
   <AddPostForm closeModal={closeModal}/>
  </div>
}
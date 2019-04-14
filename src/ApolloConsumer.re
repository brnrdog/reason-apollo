open ApolloClient;

[@bs.module "react-apollo"]
external apolloConsumer: ReasonReact.reactClass = "ApolloConsumer";

let make = (children: generatedApolloClient => ReasonReact.reactElement) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=apolloConsumer,
    ~props=Js.Obj.empty(),
    children,
  );
/**
 * This is a wrapper created to let this component be used from the new React api.
 * Please convert this component to a [@react.component] function and then remove this wrapping code.
 */
let make =
  ReasonReactCompat.wrapReasonReactForReact(
    ~component=ReasonReact.statelessComponent("TemporaryRefactorComponent"),
    (reactProps: {. "children": 'children}) =>
    make(reactProps##children)
  );
[@bs.obj]
external makeProps: (~children: 'children, unit) => {. "children": 'children} =
  "";

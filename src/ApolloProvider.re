open ApolloClient;

[@bs.module "react-apollo"]
external apolloProvider: ReasonReact.reactClass = "ApolloProvider";

let make = (~client: generatedApolloClient, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=apolloProvider,
    ~props={"client": client},
    children,
  );
/**
 * This is a wrapper created to let this component be used from the new React api.
 * Please convert this component to a [@react.component] function and then remove this wrapping code.
 */
let make =
  ReasonReactCompat.wrapReasonReactForReact(
    ~component=ReasonReact.statelessComponent("TemporaryRefactorComponent"),
    (
      reactProps: {
        .
        "client": 'client,
        "children": 'children,
      },
    ) =>
    make(~client=reactProps##client, reactProps##children)
  );
[@bs.obj]
external makeProps:
  (~children: 'children, ~client: 'client, unit) =>
  {
    .
    "client": 'client,
    "children": 'children,
  } =
  "";

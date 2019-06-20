# satelite-launch

ReasonReact dojo at Reason Prague, June 20th 2019

## initial setup

Prereqs are git, npm/yarn, editor with https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode

## Run Project

```sh
yarn install
yarn start
# in another tab
yarn server
# open localhost:8000
```

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 yarn server`).

## Dojo Instructions

Get your editor set up and start the project according to instruction [above](#run-project)

### Add Falcon9 component

Create a Falcon9 component in ReasonReact and use it in TSApp in place of TSPlaceholder component.

Falcon9 should consist of several subcomponents - Rocket, Payload, Fire. We have created these in typescript as TSRocket, TSPayload, and TSFire. 

You will need to write reason wrappers for these components to be able to use them from reason. Take a look at Rocket.re for an inspiration.

To properly style the rocket, wrap your Rocket, Payload and Fire components with `<div>` with a `className` of `"rocket"`.

Here is an example of how to do string templating in reason
```reason
<div className={j|rocket|j}>
  ...
</div>
```

### Start the countdown

`TSCountdown` component receives serveral props depending on the status of launch checklist

* `interval` - (number) seconds the count down should start from
* `run` - (bool) whether the countdown should run
* `onFinished` - (function) a callback to call when countdown finishes

We have prepared `UseCountDown.re` react hook for you that does the counting from `interval` down to zero. 

Use it inside the `TSCountdown` component and make sure the countdown starts counts and finishes when you complete the checklist (by clicking each item).

### Launch the rocket

Your `Falcon9` component should receive a prop called `launch` and return a `<div>` wrapping your `<Payload /> <Rocket /> <Fire />` components. To launch your rocket add `"launched"` to the `className` of the wrapping div.


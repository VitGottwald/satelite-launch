import { ReactNode, ComponentType } from "react";

export type reactElement = ReactNode

export type element = ReactNode

export type componentLike<props, element> = ComponentType<props>

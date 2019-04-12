import * as React from 'react'
import * as App from './App.gen'

export const blah = ({ text }: { text: string }) => <div>{text}<App.make sth="Pepa" /></div>;
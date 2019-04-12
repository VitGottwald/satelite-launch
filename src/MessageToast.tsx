import * as React from 'react'
import * as App from './App.gen'

const messageToast = ({ text }: { text: string }) => <div>{text}<App.make sth="Pepa" /></div>;

export default messageToast;

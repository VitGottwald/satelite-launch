import * as React from 'react';
// import useCountDown from './UseCountDown.gen';

const TSCountDown = ({
  interval,
  run,
  onFinished,
}: {
  interval: number;
  run: boolean;
  onFinished: () => void;
}) => {
  const timeToLaunch = interval;

  return <div className="countdown">{timeToLaunch}</div>;
};

export default TSCountDown;

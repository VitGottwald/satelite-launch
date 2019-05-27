import * as React from 'react';
const {useState, useEffect} = React;

const useCountDown = (
  interval: number,
  run: boolean,
  onFinished: () => void
) => {
  const [timeToLaunch, setTimeToLaunch] = useState(interval);

  useEffect(() => {
    if (run) {
      if (timeToLaunch > 0) {
        const timerId = setTimeout(() => {
          setTimeToLaunch(timeToLaunch - 1);
        }, 1000);
        return () => clearInterval(timerId);
      } else {
        onFinished();
        return;
      }
    }
  }, [run, timeToLaunch, onFinished]);

  return timeToLaunch;
};

const TSCountDown = ({
  interval,
  run,
  onFinished,
}: {
  interval: number;
  run: boolean;
  onFinished: () => void;
}) => {
  const timeToLaunch = useCountDown(interval, run, onFinished);

  return <div className="countdown">{timeToLaunch}</div>;
};

export default TSCountDown;

import './App.css';

import * as React from 'react';
import TSCheckList from './TSCheckList';
import TSCountDown from './TSCountDown';
import TSFalcon9 from './Falcon9.gen';

const {useState, useCallback} = React;

const TSApp = () => {
  const [checkListCompleted, setCheckListCompleted] = useState(false);
  const [countingFinished, setCountingFinished] = useState(false);
  const launch = useCallback(() => {
    setCountingFinished(true);
  }, []);

  const launchNow = checkListCompleted && countingFinished;

  return (
    <div className="container">
      <div className="left">
        <TSFalcon9 launch={launchNow} />
      </div>
      <div className="right">
        <TSCheckList onChange={setCheckListCompleted} />
        <TSCountDown
          onFinished={launch}
          run={checkListCompleted}
          interval={10}
        />
      </div>
    </div>
  );
};

export default TSApp;

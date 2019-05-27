import './App.css';

import * as React from 'react';
import TSCheckList from './TSCheckList';
import TSCountDown from './TSCountDown';

const {useState, useCallback} = React;

const TSApp = () => {
  const [checkListComplete, setCheckListComplete] = useState(false);
  const [countDownComplete, setCountDownComplete] = useState(false);
  const launch = useCallback(() => {
    setCountDownComplete(true);
  }, []);

  return (
    <div className="container">
      <div className="left">
        <span />
      </div>
      <div className="right">
        <TSCheckList onChange={setCheckListComplete} />
        <TSCountDown
          onFinished={launch}
          run={checkListComplete}
          interval={10}
        />
      </div>
    </div>
  );
};

export default TSApp;

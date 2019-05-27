import {hot} from 'react-hot-loader/root';
import './App.css';

import * as React from 'react';
import TSCheckList from './TSCheckList';
import TSCountDown from './TSCountDown';
import TSPlaceHolder from './TSPlaceHolder';

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
        {/* Falcon9 belongs here */}
        <TSPlaceHolder />
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

export default hot(TSApp);

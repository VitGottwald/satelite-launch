import './App.css';

import * as React from 'react';
import TSMessageToast from './TSMessageToast';
import TSCheckList from './TSCheckList';
import TSCountDown from './TSCountDown';
import Falcon9 from './Falcon9.gen';
import {make as MessageToast} from './MessageToast.gen';

const {useState, useCallback, useReducer} = React;

const TSApp = ({title}: {title: string}) => {
  const [checkListCompleted, setCheckListCompleted] = useState(false);
  const [countingFinished, setCountingFinished] = useState(false);
  const launch = useCallback(() => {
    setCountingFinished(true);
  }, []);

  const animationClass =
    checkListCompleted && countingFinished ? 'launched' : '';

  return (
    <div className="container">
      <div className="left">
        <Falcon9 className={animationClass} />
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

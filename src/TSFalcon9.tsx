import * as React from 'react';
import TSPayload from './TSPayload';
import TSRocket from './TSRocket';
import TSFire from './TSFire';

const Falcon9 = ({launch}: {launch: boolean}) => {
  const launchClass = launch ? 'launched' : '';

  return (
    <div className={`rocket ${launchClass}`}>
      <TSPayload />
      <TSRocket />
      <TSFire />
    </div>
  );
};

export default Falcon9;

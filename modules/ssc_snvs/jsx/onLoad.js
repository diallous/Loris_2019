/* global formatColumn */

import AccessProfilePanel from './AccessProfilePanel';

$(function() {
  ReactDOM.render(
    <AccessProfilePanel />,
    document.getElementById("openprofile")
  );
  ReactDOM.render(<DynamicDataTable
    DataURL={`${loris.BaseURL}/ssc_snvs/?format=json`}
    getFormattedCell={formatColumn}
    freezeColumn="PSCID"
    />,
    document.getElementById("datatable")
  );
});

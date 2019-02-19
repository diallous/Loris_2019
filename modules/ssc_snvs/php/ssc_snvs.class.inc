<?php
/**
* The ssc_snvs list menu
*
* PHP Version 5
*
* @category Main
* @package  SSC_SNVs
* @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
* @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
* @link     https://www.github.com/aces/Loris/
*/
namespace LORIS\ssc_snvs;
//use LORIS\sample_parameters as CP;
/**
 * Implements the ssc_snvs menu
 *
* @category Main
* @package  SSC_SNVs
* @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
* @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
* @link     https://www.github.com/aces/Loris/
 */
class SSC_SNVs extends \NDB_Menu_Filter
{
    var $AjaxModule = true;
    /**
     * Overloading this method to allow access to site users (their own site only)
     * and users w/ multisite privs
     *
     * @return true if user has access, false otherwise
     */
    function _hasAccess()
    {
        // create user object
        $user =& \User::singleton();
        $aap  = $user->hasPermission('access_all_profiles');
        $this->tpl_data['access_all_profiles'] = $aap;
        return (
            $user->hasPermission('access_all_profiles')
            || ($user->hasStudySite() && $user->hasPermission('data_entry'))

        );
    }

    /**
     * Sets up all the class variables needed for the ssc_snvs menu
     * filter
     *
     * @return true on success
     */
    function _setupVariables()
    {
        $user   =& \User::singleton();
        $config =& \NDB_Config::singleton();

        $this->tpl_data['toggled_visible'] =false;

        // set the class variables
        $useProjects = $config->getSetting("useProjects");
        if ($useProjects === "false") {
            $useProjects = false;
        }

        // set the class variables 
        // columns to display in datatable
	//issid fss iid fid pid mid chr start stop type 
        $this->columns = array(
                          'ssc_mcg_snvs.issid AS ISSID',
                          'ssc_mcg_snvs.iid AS IID',
                          'ssc_mcg_snvs.fss AS FSS',
                          'ssc_mcg_snvs.fid AS FID',
                          'ssc_mcg_snvs.chr AS CHR',
                          'ssc_mcg_snvs.start AS START',
                          'ssc_mcg_snvs.ref AS REF',
                          'ssc_mcg_snvs.alt AS ALT',
                          'ssc_mcg_snvs.snv_ano AS SNV_AnnoID',
                         );

        $this->formToFilter = array(
                               'ISSID'		=> 'ssc_mcg_snvs.isssid',
                               'IID'		=> 'ssc_mcgsnvs.iid',                               
                               'FSS'		=> 'ssc_mcg_snvs.fss',
                               'FID'		=> 'ssc_mcg_snvs.fid',
                               'CHR'		=> 'ssc_mcg_snvs.chr',                               
                               'START'		=> 'ssc_mcg_snvs.start',
                               'REF'    	=> 'ssc_mcg_snvs.ref',   
                               'ALT'		=> 'ssc_mcg_snvs.alt', 
                               'SNV_AnnoID'	=> 'ssc_mcg_snvs.snv_ano',
                              );


        $this->validFilters = array(
                               'ssc_mcg_snvs.issid',
                               'ssc_mcg_snvs.iid',			
                               'ssc_mcg_snvs.fss',
                               'ssc_mcg_snvs.fid',
                               'ssc_mcg_snvs.chr',			
                               'ssc_mcg_snvs.start',
                               'ssc_mcg_snvs.ref',
                               'ssc_mcg_snvs.alt',
                               'ssc_mcg_snvs.snv_ano',
                              );
        

        $this->query = " FROM ssc_mcg_snvs ";
        $this->order_by = '(ssc_mcg_snvs.chr) ASC';
       
        return true;
    }


    /**
     * Create the form for the ssc_snvs menu page
     *
     * @return none
     */
    function setup()
    {
        parent::setup();
        // Relying on a side-effect of the the server process module to autoload
        // its namespace.
        //\Module::factory('sample_parameters');

        // create user object
         $user    =& \User::singleton();
          $config =& \NDB_Config::singleton();
        // PSC
        if ($user->hasPermission('access_all_profiles')) {
            // get the list of study sites - to be replaced by the Site object
            $list_of_sites = \Utility::getSiteList();
            if (is_array($list_of_sites)) {
                $list_of_sites = array('' => 'All') + $list_of_sites;
            }
        } else {
            // allow only to view own site data
            $list_of_sites = $user->getStudySites();
            $list_of_sites = array('' => 'All User Sites') + $list_of_sites;
        }

        

        // add form elements
        //$this->addSelect('centerID', 'Site', $list_of_sites);
        $this->addBasicText('ISSID', 'ISSID');
        $this->addBasicText('IID', 'IID');
        $this->addBasicText('FSS', 'FSS');
        $this->addBasicText('FID', 'FID');
        $this->addBasicText('CHR', 'CHR');
        $this->addBasicText('START', 'START');
        $this->addBasicText('REF', 'REF');
        $this->addBasicText('ALT', 'ALT');
        $this->addBasicText('SNV_AnnoID', 'SNV_AnnoID');

        /*$this->addSelect(
            'gender',
            'Gender',
            array(
             ''       => 'All',
             'Male'   => 'Male',
             'Female' => 'Female',
            )
        );
        $this->addSelect(
            'Entity_type',
            'Entity Type',
            array(
             ''        => '',
             'Human'   => 'Human',
             'Scanner' => 'Scanner',
            )
        );*/
        /*$this->addSelect(
            'SubprojectID',
            'Subproject',
            array('' => 'All') + $list_of_subprojects
        );
        $this->addBasicText('dob', 'Date of Birth', array('maxlength' => 10));
        $this->addBasicText('Visit_Count', 'Number of Visits');
        $this->addSelect(
            'Latest_Visit_Status',
            'Latest Visit Status',
            $latest_visit_status_options
        );
        $this->addSelect('Feedback', 'Feedback', $feedback_status_options);
        $this->addSelect(
            'Participant_Status',
            'Participant Status',
            $participant_status_options
        );
        $this->addSelect('scan_done', 'Scan Done', $scan_options);

        // Project list, if applicable
        if ($config->getSetting("useProjects")==="true") {
            $list_of_projects = array(null => 'All');
            $projectList      = \Utility::getProjectList();
            foreach ($projectList as $key => $value) {
                $list_of_projects[$key] =$value;
            }
            $this->addSelect('ProjectID', 'Project', $list_of_projects);
        }
        if ($config->getSetting("useEDC")=="true") {
            $this->addBasicText(
                'edc',
                'EDC',
                array('maxlength' => 10)
            );
            $this->tpl_data['useEDC'] = "true";
        }
        $this->addSelect(
            'feedback',
            'Feedback Status',
            array_merge(array('' => 'All'), $feedback_status_options)
        );*/

        return true;
    }

    /**
     * Include the column formatter required to display the feedback link colours
     * in the ssc_snvs menu
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
             $baseURL . "/js/advancedMenu.js",
             $baseURL . "/ssc_snvs/js/columnFormatter.js",
             $baseURL . "/ssc_snvs/js/ssc_snvs_helper.js",
             $baseURL . "/js/components/Form.js",
             $baseURL . "/ssc_snvs/js/onLoad.js",
            )
        );
    }
}
?>
